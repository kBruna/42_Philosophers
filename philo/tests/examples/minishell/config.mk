# ==========================================================
#  Example config.mk for minishell (the framework's birthplace)
#
#  This reproduces the original hardcoded setup, now expressed
#  as configuration. Note the libft built via DEP_LIB_DIRS and
#  linked via PROJECT_LIBS, plus -lreadline.
# ==========================================================

PROJECT_SRCS = ../src/parsing/parser.c \
               ../src/parsing/parser_utils.c \
               ../src/parsing/expander/expander.c \
               ../src/parsing/expander/remove_quotes.c \
               ../src/parsing/expander/variable_expansion.c \
               ../src/parsing/expander/tilde_expansion.c \
               ../src/parsing/expander/token_insertion.c \
               ../src/parsing/fsm/set_tokens.c \
               ../src/parsing/fsm/get_token_len.c \
               ../src/parsing/fsm/input_checker.c \
               ../src/parsing/fsm/check_assignment_operator.c \
               ../src/parsing/fsm/clear_token_list.c \
               ../src/execution/redirections.c \
               ../src/execution/executor.c \
               ../src/execution/executor_utils.c \
               ../src/execution/pipes.c \
               ../src/execution/heredoc.c \
               ../src/execution/execute_builtin.c \
               ../src/utils/get_env_value.c \
               ../src/utils/setup_signals.c \
               ../src/utils/has_meaningful_content.c \
               ../src/utils/env_set.c \
               ../src/utils/env_init.c \
               ../src/utils/env_array.c \
               ../src/utils/validate_env_identifier.c \
               ../src/builtins/env.c \
               ../src/builtins/pwd.c \
               ../src/builtins/cd.c \
               ../src/builtins/exit.c \
               ../src/builtins/export.c \
               ../src/builtins/unset.c \
               ../src/builtins/echo.c \
               ../src/free/free_env_list.c \
               ../src/free/free-parser.c

PROJECT_INCLUDES = -I.. -I../lib/libft

PROJECT_LIBS = ../lib/libft/libft.a -lreadline

DEP_LIB_DIRS = ../lib/libft
