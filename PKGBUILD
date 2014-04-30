# Author: Tobias Quinn <tobias@tobiasquinn.com>
# Maintainer: Tobias Quinn <tobias@tobiasquinn.com>
pkgname=gnome-keyboard-backlight-git
pkgver=20140429
pkgrel=1
pkgdesc="Control MacBook Pro 11,1 backlight on a 10 second timer"
arch=('i686' 'x86_64')
url="https://github.com/tobiasquinn/gnome-keyboard-backlight"
license=('GPL3')
depends=('gnome-desktop')
makedepends=('git')
#conflicts=('gnome-shell-mousewheel-zoom-git')
provides=('gnome-keyboard-backlight-git')

_gitroot="git://github.com/tobiasquinn/gnome-keyboard-backlight.git"
_gitname="gnome-keyboard-backlight"

build() {
  cd "$srcdir"
  msg "Connecting to GIT server..."

  if [ -d $_gitname ] ; then
    cd $_gitname && git pull origin
    msg "The local files are updated."
  else
    git clone $_gitroot $_gitname
  fi

  msg "GIT checkout done or server timeout"
  cd ${srcdir}/$_gitname && make
  install -D -m755 ${srcdir}/$_gitname/keyboard-backlight-idler-gnome "${pkgdir}/usr/bin/keyboard-backlight-idler-gnome" || return 1
  install -D -m644 ${srcdir}/$_gitname/keyboard-backlight-idler-gnome.desktop "${pkgdir}/etc/xdg/autostart/keyboard-backlight-idler-gnome.desktop" || return 1
}

# vim:set ts=2 sw=2 et:
