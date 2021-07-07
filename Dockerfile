FROM scratch

COPY htcpcp /bin/htcpcp

# RUN /app/docker-init.sh

ENTRYPOINT ["/bin/htcpcp"]
