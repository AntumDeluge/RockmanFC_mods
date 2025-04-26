
## Patches Descriptions

### Window Title Patch

Rockman8FC_v3.13b_title:
- Changes window title from "Rockman8FC" to "Megaman8FC".

### Image Data Patch

Rockman8FC_v3.13b_image_dir:
- Loads image data from `image/image` directory instead of `image/image.bin`. However, a dummy
  `image/image.bin` file must still exist for startup to succeed.

## Patching Utilities

- [patching utilities list from ROMhacking.net](https://www.romhacking.net/?page=utilities&category=2)

### IPS

International Patching System (IPS)

- [Lunar IPS](https://www.romhacking.net/utilities/240/) (Windows)
    - Creates & applies IPS patches.
- [IPSelect](https://www.romhacking.net/utilities/14/) (Windows)
    - Applies entire or portions of IPS patches.

### BPS

Beat Protocol System (BPS)

- [beat](https://www.romhacking.net/utilities/893/) (Windows)
    - Creates & applies BPS patches.

## Convert Rockman 8 to Megaman 8

Sparkplug has provided a partial [English translation for version v2.91b](https://drive.google.com/file/d/1gTTY3I-sjL8wHyqT731iAD5E_Uhl3ZP1/view)
(shop & other in-game dialogue, such as interactions with Proto Man, not translated). Newer versions
read image data from `image/image.bin` which is an encrypted
[DxLib Game archive](https://dxlib.xsrv.jp/). In order to apply Sparkplug's translation, the game
executable must be patched to read image data from the `image/image` directory, which can be done
using the [Rockman8FC_v3.13b_image_dir](#image-data-patch) patch listed above. Once patched, copy
the `image` directory from Sparkplug's package to `image/image`. __Note:__ For the game to load
properly a file named `image/image.bin` must exist. This can simply be an empty text file.

## DxLib Game Archive Utilities

The following utilities can be used to extract the contents of `image/image.bin`:

- [DX Library](https://dxlib.xsrv.jp/dxdload.html) (includes `DxaEncode` & `DxaExtract` utilities
  for creating & extracting DxLib archives)
- [DX Library Archive tools](https://ulmf.org/threads/dx-library-archive-tools.10275/#post-953591)
  (includes modified versions of `DxaEncode` & `DxaExtract` that use decimal values for encryption
  key instead of string)
- [DXExtract](https://himeworks.com/tools/dxextract/) (dedicated DxLib extractor)
- [GARbro](https://github.com/morkt/GARbro) (supports DxLib extraction)
- [Game Ripper](https://gitlab.com/gameripper/gameripper) (supports DxLib extraction)
- [Uinversal Extractor 2](https://github.com/Bioruebe/UniExtract2) (supports DxLib extraction via
  GARbro plugin)
