# Fonts

Generate font image

```shell
qmk painter-make-font-image -s 80 -f /usr/share/fonts/opentype/unifont/unifont.otf -o graphics/fonts/unifont_80.png --no-ascii --unicode-glyphs "a1&F↕@#" 2>&1
```

Generate font

```shell
qmk painter-convert-font-image -f mono2 --no-ascii --unicode-glyphs "a1&F↕@#" -i graphics/fonts/unifont_80.png -o graphics/fonts
```