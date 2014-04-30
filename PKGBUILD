# Author: Tobias Quinn <tobias@tobiasquinn.com>
# Maintainer: Tobias Quinn <tobias@tobiasquinn.com>
pkgname=gnome-macbook-keyboard-backlight-git
pkgver=20140430
pkgrel=1
pkgdesc="Control MacBook Pro 11,1 backlight on a 10 second timer"
arch=('i686' 'x86_64')
url="https://github.com/tobiasquinn/gnome-macbook-keyboard-backlight"
license=('GPL3')
depends=('gnome-desktop' 'kbdlight')
makedepends=('git')
#conflicts=('gnome-shell-mousewheel-zoom-git')
provides=('gnome-keyboard-backlight-git')

_gitroot="git://github.com/tobiasquinn/gnome-macbook-keyboard-backlight.git"
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
  install -D -m755 ${srcdir}/$_gitname/gnome-macbook-keyboard-backlight "${pkgdir}/usr/bin/gnome-macbook-keyboard-backlight" || return 1
  install -D -m644 ${srcdir}/$_gitname/gnome-macbook-keyboard-backlight.desktop "${pkgdir}/etc/xdg/autostart/gnome-macbook-keyboard-backlight.desktop" || return 1
}

# vim:set ts=2 sw=2 et:
