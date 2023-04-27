# sudo docker build -t finale .
# sudo docker run -d -p 1337:1337 --rm -it finale
#
# with the --rm, used, for deleting the container.

FROM ubuntu:latest

# Update system
RUN apt-get update

# Add the ctf user and the shell
RUN mkdir /home/finale
RUN useradd -d /home/finale -m -p finale -s /bin/bash finale
RUN echo "finale:finale" | chpasswd

# Move to the workdir
WORKDIR /home/finale

# Copy the files into the container
COPY flag.txt /home/finale
COPY theboss /home/finale
COPY ynetd /home/finale

# Change owner to root
RUN chown -R root:root /home/finale

# Expose a port and run the elf, using the ynetd tool
USER finale
EXPOSE 1337
CMD ./ynetd -p 1337 ./theboss