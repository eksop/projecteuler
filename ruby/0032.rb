#!/usr/bin/ruby

def solution
  count = 0
  for i in 1..99
    for j in 1..999
      for k in 1..9999
        count += 1
        puts "Found : [#{i}] [#{j}] [#{k}]" if check_no(i, j, k)
        puts "Debug : [#{i}] [#{j}] [#{k}]" if count % 100000 == 0
      end
    end
  end
end

def check_no(a, b, c)

  $digits = []
  
  a.to_s.split(//).each do |d|
    $digits << d
  end

  b.to_s.split(//).each do |d|
    $digits << d
  end

  c.to_s.split(//).each do |d|
    $digits << d
  end

  return false if check_pan($digits) == false

  if (a * b == c)
    puts "#{a} * #{b} == #{c}"
    return true
  end

  if (b * c == a)
    puts "#{b} * #{c} == #{a}"
    return true
  end

  if (c * a == b)
    puts "#{c} * #{a} == #{b}"
    return true
  end

  return false
end
      
def check_pan(a)

  return false if a.count > 9
  
  if a.count == a.uniq.count
    return true
  end
  
  return false
end

$Main
solution
