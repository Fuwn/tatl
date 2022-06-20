project_test_files += files('addition.c', 'macro.c')


executable('addition',
           ['addition.c'],
           include_directories : public_header_files,
           link_with : [project_target],
           c_args : project_build_args)

executable('macro',
           ['macro.c'],
           include_directories : public_header_files,
           link_with : [project_target],
           c_args : project_build_args)
