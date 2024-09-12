TOP_PATH := $(shell pwd)
# Sanity check
ifeq ($(wildcard $(TOP_PATH)/kconfig/conf.c),)
  $(error Setup tools can't be found)
endif

# Include rules for menuconfig
include $(TOP_PATH)/Scripts/config.mk
