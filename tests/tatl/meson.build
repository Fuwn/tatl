tatl_test_files = ['test.c']
tatl_test = executable('tatl_test',
                       [tatl_test_files],
                       dependencies : [project_dep],
                       c_args : project_build_args,
                       install : true)
project_test_files += files(tatl_test_files)
