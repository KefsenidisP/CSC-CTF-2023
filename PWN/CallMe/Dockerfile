FROM ubuntu:latest

# Update system
RUN apt-get update

# Add the ctf user and the shell
RUN mkdir /home/callme
RUN useradd -d /home/callme -m -p callme -s /bin/bash callme
RUN echo "callme:callme" | chpasswd

# Move to the workdir
WORKDIR /home/callme

# Copy the files into the container
COPY flag.txt /home/callme
COPY callme /home/callme
COPY ynetd /home/callme

# Change owner to root
RUN chown -R root:root /home/callme

# Expose a port and run the elf, using the ynetd tool
USER callme
EXPOSE 32021
CMD ./ynetd -p 32021 ./callme
