FROM minextu/sdl2-cross-platform

COPY . SuperMarioClone/

WORKDIR SuperMarioClone

RUN mkdir build
WORKDIR build
RUN ls
RUN cmake ..
RUN make

ENTRYPOINT [ "./uMario" ]