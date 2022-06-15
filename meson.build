project('tatl',
        'c',
        version : '0.1.0',
        license : ['GPL-3.0-only'],
        default_options : [
          'buildtype=release',
          'c_std=c89',
          'strip=true',
          'warning_level=3',
        ])

library_path = []
project_source_files = []
project_header_files = []
project_test_files = []
project_benchmark_sources = []
public_header_files = [include_directories('include')]
project_build_args = [
  '-std=c89',
  '-Weverything',
  '-D_CRT_SECURE_NO_WARNINGS',
]
project_description = 'Tiny Test Framework for C89'

subdir('src')
subdir('include')

project_target = static_library(meson.project_name(),
                                project_source_files,
                                c_args : project_build_args,
                                gnu_symbol_visibility : 'hidden',
                                include_directories : public_header_files,
                                install : true)
project_dep = declare_dependency(include_directories : public_header_files,
                                 link_with : project_target)

set_variable(meson.project_name() + '_dep', project_dep)
subdir('examples')
subdir('tests')
install_headers(project_header_files, subdir : meson.project_name())

pkg_mod = import('pkgconfig')

import('pkgconfig').generate(description : project_description,
                             filebase : meson.project_name(),
                             libraries : project_target,
                             name : meson.project_name(),
                             subdirs : meson.project_name())

run_target('format',
           command : [
             'clang-format',
             '-i',
             '-style=LLVM',
             project_source_files,
             project_test_files,
             project_header_files,
           ])

run_target('tidy',
           command : [
             'run-clang-tidy',
             # '-fix',
             '-j',
             '8',
             'files',
             '.', # '^((?!(fuwn)).)*$',
             '-format',
             '-p=' + meson.build_root()
           ])
