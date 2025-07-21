# Dockerfile para entorno 42 con MiniLibX
FROM ubuntu:22.04

# Evita problemas con el sistema de paquetes
ENV DEBIAN_FRONTEND=noninteractive

# Instala dependencias comunes
RUN apt update && apt install -y \
    build-essential \
    clang \
    git \
    make \
    libxext-dev \
    libbsd-dev \
    libxrandr-dev \
    libxrender-dev \
    libglx-dev \
    libxfixes-dev \
    libxi-dev \
    libgl1-mesa-dev \
    vim \
    curl \
    sudo \
    && apt clean

# Crea un usuario normal para evitar usar root (recomendado)
RUN useradd -ms /bin/bash student && echo "student ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER student
WORKDIR /home/student


RUN make

# Vuelve al workspace
WORKDIR /home/student/workspace
