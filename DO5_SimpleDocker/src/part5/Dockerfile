FROM nginx:latest
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./server.c /home/server.c
COPY ./run.sh /home/run.sh
RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev && \
    rm -rf /var/lib/apt/lists/*
RUN mkdir -p /etc/nginx /var/cache/nginx /home /var/run && \
    chown -R nginx:nginx /etc/nginx /var/cache/nginx /home && \
    touch /var/run/nginx.pid && \
    chown -R nginx:nginx /var/run/nginx.pid
USER nginx
ENTRYPOINT ["sh", "./run.sh"]
HEALTHCHECK --interval=30s --timeout=5s --start-period=5s \
CMD curl -f http://localhost || exit 1