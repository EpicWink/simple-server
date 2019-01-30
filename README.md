# Simple server
A simple HTTP server to test Docker environments.

## Prerequisites
You'll need [`docker`](https://www.docker.com/products/docker-engine) to build and run these images. For Ubuntu ([documentation](https://docs.docker.com/install/linux/docker-ce/ubuntu/):
```bash
sudo apt install apt-transport-https ca-certificates curl gnupg-agent software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs)  stable"
sudo apt install docker-ce
sudo adduser $USER docker  # requires re-log
```

For Windows, visit [the documentation](https://docs.docker.com/docker-for-windows/install/).
