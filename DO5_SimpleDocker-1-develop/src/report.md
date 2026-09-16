## Part 1. Ready-made docker

Take the official docker image from nginx and download it using `docker pull`.

![alt text](images/image.jpg)

Check for the docker image to exist with `docker images`.

![alt text](images/image-1.jpg)

Run docker image with `docker run -d [image_id|repository]`.

![alt text](images/image-2.jpg)

`-d` - is a flag that tell Docker to run container in detached mode. Container will work in the background, and command line will be free for further use.

Check that the image is running with `docker ps`.

![alt text](images/image-3.jpg)

View container information with `docker inspect [container_id|container_name]`.

![alt text](images/image-4.jpg)

From the command output define and write in the report the container size, list of mapped ports and container ip.
Container size:

![alt text](images/image-5.jpg)

List of mapped ports:

![ports](images/image-6.jpg)

Container IP:

![IPAddress](images/image-7.jpg)

Stop docker container with `docker stop [container_id|container_name]`.
Check that the container has stopped with `docker ps`.

![stop](images/image-8.jpg)

Run docker with ports 80:80 and 443:443 in container, mapped to the same ports on the local machine, with `run` command.
Check that the nginx start page is available in the browser at localhost:80.

![webpage](images/image-9.jpg)

Restart docker container with `docker restart [container_id|container_name]`.
Check in any way that the container is running.

![restart](images/image-10.jpg)

## Part 2. Operations with container

Read the nginx.conf configuration file inside the docker container with the `docker exec` command.

![read](images/image-11.jpg)

Create local `nginx.conf` file with command `touch nginx.conf`.
Configure it on the `/status` path to return the nginx server status page.

![file_conf](images/image-12.jpg)

Copy the created `nginx.conf` file inside the docker image using the `docker cp` command.

![copying](images/image-13.jpg)

Restart nginx inside the docker image with `docker exec [container_id|container_name] nginx -s reload`.

![reload](images/image-14.jpg)

Check that `localhost:80/status` returns the nginx server status page.

![alt text](images/image-002.jpg)

Export the container to a `container.tar` file with the `docker export` command.
Stop the container.

![export_stop](images/image-15.jpg)

Delete the image with `docker rmi -f [image_id|repository]` without removing the container first.

![image_delete](images/image-16.jpg)

Delete stopped container with `docker rm [container_id|container_name]`

![delete_cont](images/image-17.jpg)

Import the container back using the `docker import` command.
Run the imported container with `docker run`.

![import_run](images/image-18.jpg)

Check that `localhost:80/status` returns the nginx server status page.

![alt text](images/image-001.jpg)

## Part 3. Mini web server

Write a mini server in C and FastCgi that will return a simple page saying `Hello World!`.

To make an own mini web-server it's needed to create `.c` file where server's logic will be described (with "Hello World!"). And need to make `nginx.conf` file which will proxy all requests from port 81 to port 127.0.0.1:8080.

![server](images/image-19.jpg)

Now run new docker image with new container with `docker run -d -p 81:81 nginx`. 

![run_image](images/image-21.jpg)

Then copy config and logic of server to new container with `docker cp nginx.conf`.

![copy](images/image-22.jpg)

Install required utilities to run mini web-server on FastCGI, in particular `spawn-fcgi` and `libfcgi-dev`.

![update](images/image-23.jpg)

Compile and run mini web-server with `spawn-fcgi` on port 8080.

![reload](images/image-24.jpg)

Check that browser on localhost:81 returns the page you wrote.

![alt text](images/image-23.jpg)

## Part 4. Your own docker

Write your own docker image that:
1) builds mini server sources on FastCgi from [Part 3](#part-3-mini- web-server);
2) runs it on port 8080;
3) copies inside the image written `./nginx/nginx.conf`;
4) runs `nginx`.

Build the written docker image with `docker build`, specifying the name and tag of our container.

![build](images/image-25.jpg)

Check with docker images that everything is built correctly with `docker images`.

![images](images/image-26.jpg)

Run the built docker image by mapping port 81 to 80 on the local machine and mapping the `./nginx` folder inside the container to the address where the nginx configuration files are located (see Part 2).
Check that the page of the written mini server is available on localhost:80.
Add proxying of `/status` page in `./nginx/nginx.conf` to return the nginx server status.

![run_build](images/image-27.jpg)

Restart docker image.
*If everything is done correctly, after saving the file and restarting the container, the configuration file inside the docker image should update itself without any extra steps
Check that localhost:80/status now returns a page with nginx status.

![alt text](images/image-003.jpg)

## Part 5. Dockle

First, install dockle.

Fix the image so that there are no errors or warnings when checking with dockle.

![](images/image-31.jpg)

![](images/image-32.jpg)


## Part 6. Basic Docker Compose

Stop all containers and change files.

Write a docker-compose.yml file, using which:
1) Start the docker container from Part 5 (it must work on local network, i.e., you don't need to use EXPOSE instruction and map ports to local machine).

![alt text](images/image-44.jpg)


2) Start the docker container with nginx which will proxy all requests from port 8080 to port 81 of the first container.

![alt text](images/image-38.jpg)

![alt text](images/image-37.jpg)

Map port 8080 of the second container to port 80 of the local machine.
Stop all running containers.
Build and run the project with the docker-compose build and docker-compose up commands.

![alt text](images/image-39.jpg)

Check that the browser returns the page you wrote on localhost:80 as before.

![web_return](images/image-40.jpg)