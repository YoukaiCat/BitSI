FROM debian:latest

MAINTAINER Vladislav Mileshkin "noein93@gmail.com"

RUN apt-get update
RUN apt-get install -y \
  libncurses5-dev \
  libreadline-dev \
  nettle-dev \
  libgnutls28-dev \
  build-essential \
  cmake \
  wget

RUN wget https://github.com/msgpack/msgpack-c/releases/download/cpp-1.3.0/msgpack-1.3.0.tar.gz && \
  tar -xzf msgpack-1.3.0.tar.gz && \
  cd msgpack-1.3.0 && mkdir build && cd build && \
  cmake -DMSGPACK_CXX11=ON -DMSGPACK_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=/usr .. && \
  make -j && \
  make install

RUN wget https://github.com/savoirfairelinux/opendht/archive/master.tar.gz && \
  tar -xzf master.tar.gz && \
  cd opendht-master && mkdir build && cd build && \
  cmake -DOPENDHT_PYTHON=OFF -DCMAKE_INSTALL_PREFIX=/usr .. && \
  make -j && \
  make install

ENTRYPOINT ["dhtnode", "-p"]
CMD ["55333"] #default argument
