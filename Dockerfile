# Use the official Alpine Linux as the base image
FROM alpine:latest

# Set the working directory inside the container
WORKDIR /app

# Install build tools and dependencies
RUN apk update && \
    apk upgrade && \
    apk add --no-cache cmake make g++ # Add any other necessary dependencies here

# Copy the necessary files from your project to the container
COPY . /app
COPY CMakeLists.txt /app

# Create the build directory and build the project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

# Run unit tests and start the HTTP server on port 8080
CMD ./build/SimpleHttpServer -p 8080