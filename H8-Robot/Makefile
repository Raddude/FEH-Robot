TARGET = H8-Robot

GITBINARY := git
FEHURL := google.com
FIRMWAREREPO := fehproteusfirmware

ifeq ($(OS),Windows_NT)	
	SHELL := CMD
endif

all:
ifeq ($(OS),Windows_NT)	
# check for internet connection
# if there's internet, check to see if FEHRobotController folder exists
# if it does, remove it before cloning the repo
	@ping -n 1 -w 1000 $(FEHURL) > NUL & \
	if errorlevel 1 \
	( \
		( echo "Warning: No internet connection!" ) \
	) \
	else \
	( \
		( if exist "$(FIRMWAREREPO)" \
		( \
			cd $(FIRMWAREREPO) && \
			$(GITBINARY) stash && \
			$(GITBINARY) pull && \
			cd .. \
		) \
		else \
		( \
			$(GITBINARY) config --global http.sslVerify false  && \
			$(GITBINARY) clone https://code.osu.edu/fehelectronics/proteus_software/$(FIRMWAREREPO).git \
		) \
		) \
	) 
else
# Mac/Linux
	@ping -c 1 -W 1000 $(FEHURL) > NUL ; \
	if [ "$$?" -ne 0 ]; then \
		echo "Warning: No internet connection to redmine!"; \
	else \
		if [ -d "$(FIRMWAREREPO)" ]; then \
			cd $(FIRMWAREREPO) ; \
			$(GITBINARY) stash ; \
       		$(GITBINARY) pull ; \
       		cd .. ; \
		else \
       		$(GITBINARY) clone https://code.osu.edu/fehelectronics/proteus_software/$(FIRMWAREREPO).git ; \
		fi \
	fi \

endif
	@cd $(FIRMWAREREPO) && make all TARGET=$(TARGET)

deploy:
	@cd $(FIRMWAREREPO) && make deploy TARGET=$(TARGET)

clean:
	@cd $(FIRMWAREREPO) && make clean TARGET=$(TARGET)

run:
	@cd $(FIRMWAREREPO) && make run TARGET=$(TARGET)