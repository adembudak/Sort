# ----------------------------------
# Options affecting listfile parsing
# ----------------------------------
with section("parse"):

  additional_commands = { 'foo': { 'flags': ['BAR', 'BAZ'],
             'kwargs': {'DEPENDS': '*', 'HEADERS': '*', 'SOURCES': '*'}}}
  override_spec = {}
  vartags = []
  proptags = []

# -----------------------------
# Options affecting formatting.
# -----------------------------
with section("format"):
  disable = False 

  line_width = 110
  tab_size = 2
  use_tabchars = False

  fractional_tab_policy = 'use-space'
  max_subgroups_hwrap = 2
  max_pargs_hwrap = 10
  dangle_parens = False

  max_rows_cmdline = 2
  separate_ctrl_name_with_space = False
  separate_fn_name_with_space = True

  dangle_align = 'prefix-indent'

  min_prefix_chars = 3
  max_prefix_chars = 10
  max_lines_hwrap = 2

  line_ending = 'unix'
  command_case = 'lower'
  keyword_case = 'upper'

  always_wrap = []
  enable_sort = False
  autosort = False
  require_valid_layout = False

  layout_passes = {}

# ------------------------------------------------
# Options affecting comment reflow and formatting.
# ------------------------------------------------
with section("markup"):
  bullet_char = ' '
  enum_char = ' '
  first_comment_is_literal = True

  literal_comment_pattern = None
  fence_pattern = '^\\s*([`~]{3}[`~]*)(.*)$'
  ruler_pattern = '^\\s*[^\\w\\s]{3}.*[^\\w\\s]{3}$'
  explicit_trailing_pattern = '#<'

  hashruler_min_length = 10
  canonicalize_hashrulers = False
  enable_markup = False

