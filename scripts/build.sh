#!/usr/bin/env bash
set -euo pipefail
# Build script for creating so_long (non-debug, but with flags suitable for debugging)
WD="$(cd "$(dirname "$0")/.." && pwd)"
BUILD="$WD/build"
mkdir -p "$BUILD"

echo "[build] Building Libft (if present)..."
if [ -d "$WD/Libft" ]; then
  make -C "$WD/Libft"
  LIBFT_FLAGS="-L$WD/Libft -lft -I$WD/Libft"
else
  LIBFT_FLAGS=""
fi

echo "[build] Preparing ft_printf flags..."
FP_FLAGS="-I$WD/ft_printf -L$WD/ft_printf -lftprintf"

echo "[build] Compiling and linking (single-step)..."
SRCS=$(find "$WD" -maxdepth 1 -type f -name "*.c")
COMMON_OBJS=()
for f in $SRCS; do
  echo "" # no-op to keep for-loop syntax
done

# Use the simpler top-level invocation for the non-debug build for speed and compatibility
cc -g -O0 -fno-omit-frame-pointer so_long.c map_get.c ft_printf/*.c GetNextLine/*.c -Ift_printf -IGetNextLine $LIBFT_FLAGS -Lft_printf -lftprintf -o so_long
echo "[build] Built: $WD/so_long"
