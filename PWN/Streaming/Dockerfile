# sudo docker build -t streaming .
# sudo docker run -d -p 32020:32020 --rm -it streaming
#
# with the --rm, used, for deleting the container.

FROM ubuntu:latest

# Update system
RUN apt-get update

# Add the ctf user and the shell
RUN mkdir /home/streaming
RUN useradd -d /home/streaming -m -p streaming -s /bin/bash streaming
RUN echo "streaming:streaming" | chpasswd

# Move to the workdir
WORKDIR /home/streaming

# Copy the files into the container
COPY flag.txt /home/streaming
COPY streaming /home/streaming
COPY ynetd /home/streaming

# Change owner to root
RUN chown -R root:root /home/streaming

# Expose a port and run the elf, using the ynetd tool
USER streaming
EXPOSE 32020
CMD ./ynetd -p 32020 ./streaming