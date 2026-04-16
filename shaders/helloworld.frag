// https://thebookofshaders.com/02/

#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;

void main() {
	gl_FragColor = vec4(
        abs(sin(u_time)),
        0.5,
        1.0,
        abs(sin(gl_FragCoord.x*0.02+gl_FragCoord.y*0.04)));
}
