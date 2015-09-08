# Adjust brightness for ThinkPad X230

Helps set the brightness outside X server for ThinkPad X230. Probably works
with other laptops making use of `/sys/class/backlight`.

The idea was to create a binary which will have a sticky UID so no root is
necessary.

# Installation

```bash
# clone the repository
git clone https://github.com/jeremija/bright
cd bright

# build
make

# to install binary in /usr/local/bin
sudo make install
```

# Usage

```bash
bright [-|+]<percentage>

# decrease brightness by 10%:
bright -10

# increase brightness by 10%:
bright +10

# set brightness to 70%:
bright 70
```

The default brightness backend is set to `intel_backlight`. The
`BRIGHT_BACKEND` environment variable can be used to override the default
setting. Check the `/sys/class/backlight` directory to find which backend to
use.

# License

MIT
