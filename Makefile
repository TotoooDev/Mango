# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Mango_config = debug

else ifeq ($(config),release)
  Mango_config = release

else ifeq ($(config),distribution)
  Mango_config = distribution

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := Mango

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Mango:
ifneq (,$(Mango_config))
	@echo "==== Building Mango ($(Mango_config)) ===="
	@${MAKE} --no-print-directory -C Mango -f Makefile config=$(Mango_config)
endif

clean:
	@${MAKE} --no-print-directory -C Mango -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo "  distribution"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Mango"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"