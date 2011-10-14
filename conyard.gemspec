Gem::Specification.new do |s|
  s.platform    = Gem::Platform::RUBY
  s.name        = 'conyard'
  s.version     = '0.1.2'
  s.summary     = 'Generators for typing-intensive programming tasks.'
  s.description = 'Conyard is a Ruby experiment in generating source code for use by C, C++, and Objective-C projects. It is designed to reduce the amount of typing (and therefore errors) introduced by sleep-deprived programmers.'

  s.required_ruby_version     = '>= 1.8.7'
  s.required_rubygems_version = ">= 1.3.6"

  s.author            = 'Christopher Miller'
  s.email             = 'lordsauronthegreat@gmail.com'
  s.homepage          = 'https://github.com/NSError/Conyard/wiki'
  s.rubyforge_project = 'conyard'

  s.bindir             = 'bin'
  s.executables        = ['conyard']
  
  s.files = [
    'tests/vector/vector_test.c',
    'tests/vector/vector_test.rake',
    'bin/conyard',
    'Rakefile',
    'README.md',
    'COPYING.md' ]
  s.files << Dir.glob("structure-kits/**/*.*")

  s.add_dependency('rake')
end