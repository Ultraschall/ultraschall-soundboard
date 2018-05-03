/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== ic_pause_circle_outline_black_48px.svg ==================
static const unsigned char temp_binary_data_0[] =
"<svg fill=\"#000000\" height=\"48\" viewBox=\"0 0 24 24\" width=\"48\" xmlns=\"http://www.w3.org/2000/svg\">\n"
"    <path d=\"M0 0h24v24H0z\" fill=\"none\"/>\n"
"    <path d=\"M9 16h2V8H9v8zm3-14C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm0 18c-4.41 0-8-3.59-8-8s3.59-8 8-8 8 3.59 8 8-3.59 8-8 8zm1-4h2V8h-2v8z\"/>\n"
"</svg>";

const char* ic_pause_circle_outline_black_48px_svg = (const char*) temp_binary_data_0;

//================== ic_play_circle_outline_black_48px.svg ==================
static const unsigned char temp_binary_data_1[] =
"<svg fill=\"#000000\" height=\"48\" viewBox=\"0 0 24 24\" width=\"48\" xmlns=\"http://www.w3.org/2000/svg\">\n"
"    <path d=\"M0 0h24v24H0z\" fill=\"none\"/>\n"
"    <path d=\"M10 16.5l6-4.5-6-4.5v9zM12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm0 18c-4.41 0-8-3.59-8-8s3.59-8 8-8 8 3.59 8 8-3.59 8-8 8z\"/>\n"
"</svg>";

const char* ic_play_circle_outline_black_48px_svg = (const char*) temp_binary_data_1;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) noexcept
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x4d65c42f:  numBytes = 316; return ic_pause_circle_outline_black_48px_svg;
        case 0x0c1caad7:  numBytes = 311; return ic_play_circle_outline_black_48px_svg;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "ic_pause_circle_outline_black_48px_svg",
    "ic_play_circle_outline_black_48px_svg"
};

const char* originalFilenames[] =
{
    "ic_pause_circle_outline_black_48px.svg",
    "ic_play_circle_outline_black_48px.svg"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8) noexcept
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
