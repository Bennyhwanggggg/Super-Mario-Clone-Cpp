FROM auchida/freebsd

LABEL author="Benny Hwang"

RUN pkg install cmake sdl2 sdl2_image sdl2_mixer

COPY . supermario/

WORKDIR supermario/

RUN mkdir build
RUN cd build
RUN cmake ..
RUN make

ENTRYPOINT [ "./uMario" ]
