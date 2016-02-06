#!/usr/bin/env ruby
# encoding: utf-8

image = "youkaicat/opendht"
port = 55333
count = 4

puts "#{image}, #{port}, #{count}"

first_id = `docker run -itd #{image} #{port}`.strip
first_ip = `docker inspect --format '{{ .NetworkSettings.IPAddress }}' #{first_id}`.strip

count.times do |i|
  id = `docker run -itd #{image} #{port} -b #{first_ip}:#{port}`.strip
  ip = `docker inspect --format '{{ .NetworkSettings.IPAddress }}' #{id}`.strip
  puts "#{i}: #{id[0..10]}:#{ip}"
end
