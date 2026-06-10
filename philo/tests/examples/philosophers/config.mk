# ==========================================================
#  Example config.mk for 42's Philosophers
#
#  Usage: copy this file over tests/config.mk inside your
#  philo repo and adjust the paths to match your sources.
# ==========================================================

# Every .c your tests call into — never list the one with main()!
PROJECT_SRCS = ../src/init.c \
               ../src/parse_args.c \
               ../src/time_utils.c \
               ../src/routine.c \
               ../src/monitor.c \
               ../src/utils.c

PROJECT_INCLUDES = -I.. -I../includes

PROJECT_LIBS = -pthread

# Philosophers has no external lib dependencies
DEP_LIB_DIRS =
