def emit_vector name, datatype, outfile
  @name = name
  @type = datatype
  @outfile = File.expand_path outfile
  @guard = outfile.pathmap("%n").gsub(/\-/,'_').upcase
  
  headertmpl = 'structure-kits/vector/vector.h.erb'
  impltmpl = 'structure-kits/vector/vector.c.erb'
  
  ofh=File.new(@outfile+".gen.h", "w")
  ofh.write(ERB.new(File.read(headertmpl)).result)
  ofh.close
  ofi=File.new(@outfile+".gen.c", "w")
  ofi.write(ERB.new(File.read(impltmpl)).result)
  ofi.close
end

desc "Creates a new fast, lean C vector implementation; useage is: rake vector[name, type, outfile]"
task :vector, :name, :datatype, :outfile do |t, args|
  args.with_defaults(:name => 'int_vector', :datatype => 'int', :outfile => 'int_vector')
  
  emit_vector args.name, args.datatype, File.expand_path(args.outfile)
end
