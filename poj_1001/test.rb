def work
  lines = File.read('input.txt').split("\n")
  lines.each do |line|
    v, n = line.split(' ').compact
    result = Rational(v.to_f) ** n.to_i
    puts result.to_f
  end
end

work
