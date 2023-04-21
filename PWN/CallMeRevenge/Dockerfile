# sudo docker build -t callmerevenge .
# docker run -p 32022:32022 --restart=on-failure --name=callmerevenge --detach callmerevenge
#
# with the --rm, used, for deleting the container.

FROM ubuntu:latest

# Update system
RUN apt-get update

# Add the ctf user and the shell
RUN mkdir /home/callmerevenge
RUN useradd -d /home/callmerevenge -m -p callmerevenge -s /bin/bash callmerevenge
RUN echo "callmerevenge:callmerevenge" | chpasswd

# Move to the workdir
WORKDIR /home/callmerevenge

# Copy the files into the container
COPY callmerevenge /home/callmerevenge
COPY ynetd /home/callmerevenge

# Change owner to root
RUN chown -R root:root /home/callmerevenge

# Expose a port and run the elf, using the ynetd tool
USER callmerevenge
EXPOSE 32022
CMD ./ynetd -p 32022 ./callmerevenge