TOP_PATH := $(shell pwd)
# Sanity check
ifeq ($(wildcard $(TOP_PATH)/Tools/Setup/kconfig/conf.c),)
  $(error Setup tools can't be found)
endif

# Include rules for menuconfig
include $(TOP_PATH)/Tools/Scripts/config.mk
