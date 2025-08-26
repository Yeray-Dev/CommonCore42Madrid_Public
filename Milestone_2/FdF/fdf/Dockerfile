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
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    libxrandr-dev \
    libxrender-dev \
    libglx-dev \
    libxfixes-dev \
    libxi-dev \
    libgl1-mesa-dev \
    x11-utils \
    vim \
    curl \
    sudo \
    && apt clean

# Crea un usuario normal para evitar usar root (recomendado)
RUN useradd -ms /bin/bash student && echo "student ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER student
WORKDIR /home/student

# Clona MiniLibX (puedes cambiar el repo si estás en 42 Madrid)
RUN git clone https://github.com/42Paris/minilibx-linux.git

# Compila MiniLibX
WORKDIR /home/student/minilibx-linux
RUN make

# Vuelve al workspace
WORKDIR /home/student/workspace
