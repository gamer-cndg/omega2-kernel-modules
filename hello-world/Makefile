# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

# name
PKG_NAME:=hello-world
# version of what we are downloading
PKG_VERSION:=1.1
# version of this makefile
PKG_RELEASE:=4

PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_NAME)
PKG_CHECK_FORMAT_SECURITY:=0

include $(INCLUDE_DIR)/package.mk

define KernelPackage/$(PKG_NAME)
	SUBMENU:=Other modules
	DEPENDS:=@(TARGET_ramips_mt76x8||TARGET_ramips_mt7688)
	TITLE:=Hello world kernel module
	FILES:= $(PKG_BUILD_DIR)/hello-world.ko
endef

define KernelPackage/$(PKG_NAME)/description
	A "hello world" test module for a tutorial.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

MAKE_OPTS:= \
	ARCH="$(LINUX_KARCH)" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	SUBDIRS="$(PKG_BUILD_DIR)"

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		$(MAKE_OPTS) \
		modules
endef

$(eval $(call KernelPackage,$(PKG_NAME)))