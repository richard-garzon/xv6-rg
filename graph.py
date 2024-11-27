from collections import defaultdict
import matplotlib.pyplot as plt

starting_tick = 307

data = defaultdict( lambda: defaultdict ( int ))
pid_to_tickets = defaultdict( int )

with open('logs.txt') as f:
    for line in f:
        split = line.split()

        systicks = split[3]
        systicks_colon_ind = systicks.index(':')
        systick = int(systicks[systicks_colon_ind+1:])

        pid_kv = split[0]
        pid_colon_ind = pid_kv.index(':')
        pid = pid_kv[pid_colon_ind+1:]

        ticket_kv = split[1]
        ticket_colon_ind = ticket_kv.index(':')
        tickets = ticket_kv[ticket_colon_ind+1:]

        ticks_kv = split[2]
        ticks_colon_ind = ticks_kv.index(':')
        ticks = ticks_kv[ticks_colon_ind+1:]

        data[systick][pid] = int(ticks)
        pid_to_tickets[pid] = tickets


x_values = sorted(data.keys())

all_keys = {key for s in data.values() for key in s}

print(pid_to_tickets)
for key in all_keys:
    y_values = [data[x].get(key, None) for x in x_values]
    label = f'{key} = {pid_to_tickets[key]} tickets'
    plt.plot(x_values, y_values, label=label)


plt.xlabel("system ticks")
plt.ylabel("process ticks")
plt.title("graph of process ticks over time")
plt.legend(title="boops")
plt.grid(True)

plt.show()
