# name of your application
APPLICATION = ldr_sensor

# If no BOARD is found in the environment, use this default:
BOARD ?= esp8266-esp-12x

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= /home/angela/riot_workplace/RIOT

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1
# Activate auto-configure IPv6 address for interface 10
# CONFIG_GNRC_IPV6_NIB_SLAAC=1

USEMODULE += esp_wifi
USEMODULE += arduino

#USEMODULE += gnrc_sock							# HelloWorldExample
#USEMODULE += gnrc_sock_check_reuse				# HelloWorldExample	
#USEMODULE += gnrc_sock_udp						# HelloWorldExample
USEMODULE += gnrc_ipv6							# HelloWorldExample


USEMODULE += gnrc_ipv6_nib_6lr
USEMODULE += gnrc_ipv6_nib_6ln

USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif
# Activate ICMPv6 error messages
USEMODULE += gnrc_icmpv6_error
# Specify the mandatory networking modules for IPv6 and UDP
USEMODULE += gnrc_ipv6_router_default 
USEMODULE += gnrc_udp
# Add a routing protocol
USEMODULE += gnrc_rpl
USEMODULE += auto_init_gnrc_rpl
# This application dumps received packets to STDIO using the pktdump module
USEMODULE += gnrc_pktdump
# Additional networking modules that can be dropped if not needed
USEMODULE += gnrc_icmpv6_echo
# Add also the shell, some shell commands
#USEMODULE += shell
#USEMODULE += shell_commands
#USEMODULE += ps
#USEMODULE += netstats_l2
#USEMODULE += netstats_ipv6
#USEMODULE += netstats_rpl

include $(RIOTBASE)/Makefile.include
