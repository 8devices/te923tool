#
# Copyright (C) 2012 Žilvinas Valinskas
# See LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=te923tool
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/te923tool
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Read weather station
  DEPENDS += +libusb
endef

define Package/te923tool/description
Read weather station data
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	make -C $(PKG_BUILD_DIR)		\
		$(TARGET_CONFIGURE_OPTS)	\
		CFLAGS="$(TARGET_CFLAGS) $(TARGET_CPPFLAGS)"	\
		LIBS="$(TARGET_LDFLAGS)"
endef

define Package/te923tool/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/te923con $(1)/usr/sbin/te923con
endef

$(eval $(call BuildPackage,te923tool))
