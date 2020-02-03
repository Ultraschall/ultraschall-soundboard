
$Bootstrap = $False

$ToolsDirectory = "./_tools"
$BuildDirectory = "./_build"

$JuceDirectory = "./JUCE"
$ProjucerDirectory = $JuceDirectory + "/extras/Projucer/Builds/VisualStudio2015"
$ProjucerExecutable = $ProjucerDirectory + "/x64/Release/Projucer.exe"

$ConfigureTarget = $False
$BuildTarget = $True
$BuildAction = "build"
$BuildConfiguration = "Debug"

Function Remove-Directory ($Directory) {
  If ((Test-Path -PathType Container $Directory) -ne $False) {
    Remove-Item -Recurse -Force $Directory | Out-Null
  }
}

If ($args.Count -gt 0) {
  If ($args[0] -eq "--help") {
    Write-Host "Usage: build.ps1 [ --bootstrap | --configure | --build | --rebuild | --clean ] [ --debug | --release ]"
    Return
  }
  ElseIf ($args[0] -eq "--bootstrap") {
    Remove-Directory $ToolsDirectory
    Remove-Directory $BuildDirectory
    $Bootstrap = $True
    $ConfigureTarget = $True
    $BuildTarget = $True
    $BuildAction = "build"
  }
  ElseIf ($args[0] -eq "--configure") {
    Remove-Directory $BuildDirectory
    $ConfigureTarget = $True
    $BuildAction = "rebuild"
    $BuildTarget = $True
  }
  ElseIf ($args[0] -eq "--build") {
    $BuildAction = "build"
    $BuildTarget = $True
  }
  ElseIf ($args[0] -eq "--clean") {
    $BuildAction = "clean"
    $BuildTarget = $True
  }
  ElseIf ($args[0] -eq "--rebuild") {
    $BuildAction = "rebuild"
    $BuildTarget = $True
  }
}

If ($args.Count -gt 1) {
  If ($args[1] -eq "--help") {
    Write-Host "Usage: build.ps1 [ --bootstrap | --configure | --build | --rebuild | --clean ] [ --debug | --release ]"
    Return
  }
  ElseIf ($args[1] -eq "--debug") {
    $BuildConfiguration = "Debug"
  }
  ElseIf ($args[1] -eq "--release") {
    $BuildConfiguration = "Release"
  }
}

$BuildFailed = $False

if ((Test-Path -PathType Container $ToolsDirectory) -eq $False) {
  New-Item -ItemType Directory $ToolsDirectory | Out-Null
  $Bootstrap = $True
}

if ($Bootstrap -eq $True) {
  Write-Host "Bootstrapping ultraschall-soundboard..."

  Push-Location $ToolsDirectory | Out-Null

  if ($BuildFailed -eq $False) {
    $VstSdkDirectory = "./VST_SDK"
    if ((Test-Path -PathType Container $VstSdkDirectory) -eq $False) {
      $VstSdkArchive = "./vst-sdk_3.6.14.zip"
      if ((Test-Path -PathType Leaf $VstSdkArchive) -eq $False) {
        Invoke-WebRequest -Uri "https://www.steinberg.net/vst3sdk" -OutFile $VstSdkArchive
      }

      if ((Test-Path -PathType Leaf $VstSdkArchive) -eq $True) {
        Expand-Archive -Force -Path $VstSdkArchive -DestinationPath "./"
        if ((Test-Path -PathType Container $VstSdkDirectory) -eq $True) {
          Remove-Item -Force $VstSdkArchive
        }
        else {
          $BuildFailed = $True
        }
      }
      else {
        $BuildFailed = $True
      }
    }
  }

  if ($BuildFailed -eq $False) {
    if ((Test-Path -PathType Container $JuceDirectory) -eq $False) {
      & git clone --branch 4.3.1 https://github.com/WeAreROLI/JUCE.git $JuceDirectory
      if ($LASTEXITCODE -ne 0) {
        $BuildFailed = $True
      }
    }

    if ($BuildFailed -eq $False) {
      if ((Test-Path -PathType Leaf $ProjucerExecutable) -eq $False) {
        & msbuild -nologo -m -consoleloggerparameters:ErrorsOnly -target:build -property:Configuration=Release -property:Platform="x64" -property:PlatformToolset="v142" ($ProjucerDirectory + "/Projucer.sln")
        if ($LASTEXITCODE -ne 0) {
          $BuildFailed = $True
        }
      }
    }
  }

  Pop-Location
  Write-Host "Done."
}

if ((Test-Path -PathType Container $BuildDirectory) -eq $False) {
  New-Item -ItemType Directory $BuildDirectory | Out-Null
  $ConfigureTarget = $True
}

if ($BuildFailed -eq $False) {
  if ($ConfigureTarget -eq $True) {
    Write-Host "Configuring ultraschall-soundboard..."
    Push-Location $ToolsDirectory | Out-Null

    & $ProjucerExecutable  --resave "../src/ultraschall-soundboard.jucer" | Out-Null
    if ($LASTEXITCODE -ne 0) {
      Write-Host "Update failed!"
      $BuildFailed = $True
    }

    Pop-Location
    Write-Host "Done."
  }
}

if ($BuildFailed -eq $False) {
  if ($BuildTarget -eq $True) {
    if ($BuildAction -eq "build") {
      Write-Host -NoNewline "Building"
    }
    elseif ($BuildAction -eq "rebuild") {
      Write-Host -NoNewline "Rebuilding"
    }
    elseif ($BuildAction -eq "clean") {
      Write-Host -NoNewline "Cleaning"
    }
    Write-Host " ultraschall-soundboard..."

    Push-Location $BuildDirectory | Out-Null

    & msbuild "./win32/ultraschall-soundboard.sln" -nologo -m -consoleloggerparameters:ErrorsOnly -target:$BuildAction -property:Configuration=$BuildConfiguration -property:Platform="x64" -property:PlatformToolset="v142"
    if ($LASTEXITCODE -ne 0) {
      $BuildFailed = $True
    }

    Pop-Location
    Write-Host "Done."
  }
}

if ($BuildFailed -eq $False) {
  Write-Host -NoNewline -ForegroundColor White -BackgroundColor DarkGreen "\o/"
}
else {
  Write-Host -NoNewline -ForegroundColor White -BackgroundColor DarkRed "/o\"
}
Write-Host
