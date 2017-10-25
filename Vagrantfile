# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  config.vm.box = "ubuntu/xenial64"

  # Disable automatic box update checking. If you disable this, then
  # boxes will only be checked for updates when the user runs
  # `vagrant box outdated`. This is not recommended.
  config.vm.box_check_update = false
  config.vm.provision "shell", inline: <<-SHELL
      sudo apt-get update
      sudo apt-get install -y build-essential dpkg

    # Kernel v4.11-rc1
    # This has our latest changes to BPF verifier
    # However the MAX_BPF_STACK issue hasn't been resolved.
    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.11-rc1/linux-image-4.11.0-041100rc1-generic_4.11.0-041100rc1.201703051731_amd64.deb
    #dpkg -i linux-image-4.11.0-041100rc1-generic_4.11.0-041100rc1.201703051731_amd64.deb
    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.11-rc1/linux-headers-4.11.0-041100rc1-generic_4.11.0-041100rc1.201703051731_amd64.deb
    #dpkg -i linux-headers-4.11.0-041100rc1-generic_4.11.0-041100rc1.201703051731_amd64.deb
    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.11-rc1/linux-headers-4.11.0-041100rc1_4.11.0-041100rc1.201703051731_all.deb
    #dpkg -i linux-headers-4.11.0-041100rc1_4.11.0-041100rc1.201703051731_all.deb

    wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.14-rc6/linux-image-4.14.0-041400rc6-generic_4.14.0-041400rc6.201710230731_amd64.deb
    dpkg -i linux-image-4.14.0-041400rc6-generic_4.14.0-041400rc6.201710230731_amd64.deb
    wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.14-rc6/linux-headers-4.14.0-041400rc6-generic_4.14.0-041400rc6.201710230731_amd64.deb
    dpkg -i linux-headers-4.14.0-041400rc6-generic_4.14.0-041400rc6.201710230731_amd64.deb
    wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.14-rc6/linux-headers-4.14.0-041400rc6_4.14.0-041400rc6.201710230731_all.deb
    dpkg -i linux-headers-4.14.0-041400rc6_4.14.0-041400rc6.201710230731_all.deb

    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.12.14/linux-image-4.12.14-041214-generic_4.12.14-041214.201709200843_amd64.deb
    #dpkg -i linux-image-4.12.14-041214-generic_4.12.14-041214.201709200843_amd64.deb
    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.11-rc1/linux-headers-4.12.14-041214-generic_4.12.14-041214.201709200843_amd64.deb
    #dpkg -i linux-headers-4.12.14-041214-generic_4.12.14-041214.201709200843_amd64.deb
    #wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v4.11-rc1/linux-headers-4.12.14-041214_4.12.14-041214.201709200843_all.deb
    #dpkg -i linux-headers-4.12.14-041214_4.12.14-041214.201709200843_all.deb

    # Fetch the p4xdp docker image
    curl -fsSL get.docker.com -o get-docker.sh
    sh get-docker.sh
    #apt-get install -y docker.io
    docker pull u9012063/p4xdp
  SHELL
  # reboot to the newer kernel
  config.vm.provision :reload
end

