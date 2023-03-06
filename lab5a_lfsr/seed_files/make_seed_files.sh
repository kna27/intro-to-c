
## head /dev/urandom | tr -dc A-Za-z0-9 | head -c 10 > 1_tiny.seed
shuf -zer -n10  {A..Z} {a..z} {0..9} > 1_tiny.seed
shuf -zer -n100  {A..Z} {a..z} {0..9} > 2_small.seed
shuf -zer -n1000  {A..Z} {a..z} {0..9} > 3_medium.seed
shuf -zer -n10000  {A..Z} {a..z} {0..9} > 4_large.seed
shuf -zer -n100000  {A..Z} {a..z} {0..9} > 5_huge.seed
# shuf -zer -n1000000  {A..Z} {a..z} {0..9} > 6_enormous.seed
