# Brightness switcher for ThinkPad X230

Helps set the brightness outside X server for ThinkPad X230. Probably works
with other laptops with Intel graphics cards.

The idea was to create a binary which will have a sticky UID so no root is
necessary.

# Installation

```bash
# clone the repository
git clone https://github.com/jeremija/brightness
cd brightness

# build
make

# to install binary in /usr/local/bin
sudo make install
```

# Usage

```bash
brightness [-|+]<percentage>

# example to decrease brightness for 10%:
brightness -10
```

The default brightness backend is set to `intel_backlight`. The
`BRIGHTNESS_BACKEND` environment variable can be used to override the default
setting. Check the `/sys/class/backlight` directory to find which backend to
use.

# License

MIT
