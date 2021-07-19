# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.177.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-20.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

WORKDIR /external
RUN git clone https://github.com/ROBOTIS-GIT/DynamixelSDK.git
RUN cd /external/DynamixelSDK/c++/build/linux64 \
    && make \
    && make install

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupmod --gid $USER_GID $USERNAME \
    && usermod -a -G dialout $USERNAME \
    && chown -R $USER_UID:$USER_GID /home/$USERNAME
# && usermod --uid $USER_UID --gid $USER_GID $USERNAME \
