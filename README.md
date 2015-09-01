# Brightness switcher for ThinkPad X230

Helps set the brightness outside X server for ThinkPad X230. Probably works
with other laptops with Intel graphics cards.

The idea was to create a binary which will have a sticky UID so no root is
necessary.

# Installation

```bash
git clone https://github.com/jeremija/brightness
cd brightness

make

sudo cp brightness /usr/local/bin

# add sticky UID to make it run without root
sudo chmod u+s /usr/local/bin/brightness
```

# Usage

```bash
brightness [-|+]<percentage>

# example to decrease brightness for 10%:
brightness -10
```

# License

MIT
