#!/usr/bin/env bash
set -euo pipefail
# Build script for creating so_long_debug with debug symbols
WD="$(cd "$(dirname "$0")/.." && pwd)"
BUILD="$WD/build"
mkdir -p "$BUILD"

echo "[build-debug] Building Libft (if present)..."
if [ -d "$WD/Libft" ]; then
  make -C "$WD/Libft"
  LIBFT_FLAGS="-L$WD/Libft -lft -I$WD/Libft"
else
  LIBFT_FLAGS=""
fi

echo "[build-debug] Preparing ft_printf flags..."
FP_FLAGS="-I$WD/ft_printf -L$WD/ft_printf -lftprintf"

echo "[build-debug] Compiling C sources..."
SRCS=$(find "$WD" -type f -name "*.c" -not -path "$WD/minilibx-linux/*" -not -path "$WD/.vscode/*" -not -path "$BUILD/*")
for f in $SRCS; do
  out="$BUILD/$(basename "$f" .c).o"
  echo "CC -c $f -> $out"
  cc -g -I"$WD/ft_printf" -I"$WD/GetNextLine" -I"$WD/Libft" -c "$f" -o "$out"
done

echo "[build-debug] Linking -> so_long_debug"
LIBS="$FP_FLAGS $LIBFT_FLAGS"
if [ -f "$WD/minilibx-linux/libmlx.a" ]; then
  LIBS="$LIBS -L$WD/minilibx-linux -lmlx -lX11 -lXext -lm"
fi
cc -g "$BUILD"/*.o -o "$WD/so_long_debug" $LIBS
echo "[build-debug] Built: $WD/so_long_debug"
