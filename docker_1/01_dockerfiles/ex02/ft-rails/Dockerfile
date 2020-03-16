# set the base image to alpine
FROM ruby

# set file author
MAINTAINER hkayla

# update and install tools required for project
RUN apk update && apk upgrade && apk add vim

# set the default app that will be executed when the container starts
ENTRYPOINT vim
