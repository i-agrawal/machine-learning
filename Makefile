ifeq ($(.DEFAULT_GOAL),)
.DEFAULT_GOAL := all
endif

CC := gcc
CFLAGS := -O2 -std=c99
CPPFLAGS := 
ALLGENS := 

define modrules

$(1)_headers := $(wildcard $(1)/include/*.h)
$(1)_sources := $(wildcard $(1)/src/*.c)
$(1)_objects := $(subst src,obj,$(patsubst %.c,%.o,$(wildcard $(1)/src/*.c)))
ifneq ($(wildcard $(1)/include/),)
CPPFLAGS += -I$(1)/include
endif
ALLGENS += $$($(1)_objects)

ifneq ($(wildcard $(1)/module.mk),)
include $(1)/module.mk
endif

.PHONY: $(1)
ifneq ($$($(1)_prog),)
ALLGENS += $(1)/bin/$$($(1)_prog)
$(1)_ex_objects := $$(grapher_objects) $$(matrices_objects)

$(1): $$($(1)_modules) $(1)/bin/$$($(1)_prog)

$(1)/bin/$$($(1)_prog): $$($(1)_objects) $$($(1)_ex_objects)
	$(CC) $(CFLAGS) $$(CPPFLAGS) -o $$(@) $$(^)

else
.PHONY: $(1)
$(1): $$($(1)_objects)

endif

$(1)/obj/%.o: $(1)/src/%.c $$($(1)_headers)
	$(CC) $(CFLAGS) $$($(1)_cf) $$(CPPFLAGS) -o $$(@) -c $$(<)

endef

modules := grapher matrices lessonone
.PHONY: all
all: $(modules)

$(foreach module,$(modules),$(eval $(call modrules,$(module))))

.PHONY: clean
clean:
	rm -f $(ALLGENS)
