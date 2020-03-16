# set the base image to alpine
FROM debian

# set file author
MAINTAINER hkayla

# set variables
ENV TS3SERVER_LICENSE=accept
ENV TS_DIRECTORY=/opt/teamspeak

# update, download and install tools required for project
RUN apt-get update -y && apt-get upgrade -y && apt-get install bzip2 w3m wget -y && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
  TS3SERVER_VERSION="$(w3m -dump https://www.teamspeak.com/downloads | grep -m 1 'Server 64-bit ' | awk '{print $NF}')" && \
  wget https://files.teamspeak-services.com/releases/server/${TS3SERVER_VERSION}/teamspeak3-server_linux_amd64-${TS3SERVER_VERSION}.tar.bz2 -O /tmp/teamspeak.tar.bz2 && \
  tar jxf /tmp/teamspeak.tar.bz2 -C /opt && \
  mv /opt/teamspeak3-server_* ${TS_DIRECTORY} && \
  rm /tmp/teamspeak.tar.bz2 && \
  apt-get purge -y bzip2 w3m wget && \
  apt-get autoremove -y && \
  apt-get clean -y && \
  rm -rf /var/lib/apt/lists/*

# Load in all of our config files.
ADD entrypoint.sh /entrypoint.sh

# Forward the following ports to allow connections to your TeamSpeak 3 Server using EXPOSE
# 9987  default voice
# 10011 server query
# 30033 file transport
EXPOSE 9987/udp 10011 30033 

# set the default app that will be executed when the container starts
ENTRYPOINT [ "/entrypoint.sh" ]
