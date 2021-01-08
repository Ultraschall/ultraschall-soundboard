FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && apt-get install -y locales && rm -rf /var/lib/apt/lists/* \
	&& localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG en_US.utf8

RUN apt-get update \
	&& apt-get install -y \
	build-essential \
	clang \
	git \
	ladspa-sdk \
	freeglut3-dev \
	g++ \
	libasound2-dev \
	libcurl4-openssl-dev \
	libfreetype6-dev \
	libjack-jackd2-dev \
	libx11-dev \
	libxcomposite-dev \
	libxcursor-dev \
	libxinerama-dev \
	libxrandr-dev \
	mesa-common-dev \
	webkit2gtk-4.0 \
	cmake \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/local/src/ultraschall-soundboard
COPY . /usr/local/src/ultraschall-soundboard

ENV GDK_BACKEND=x11
RUN cd /usr/local/src/ultraschall-soundboard \
	&& mkdir -p build \
	&& cd build \
	&& cmake .. \
	&& cmake --build . --config Release