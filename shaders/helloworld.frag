// https://thebookofshaders.com/02/

#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;
    vec2 m = u_mouse.xy/u_resolution;

	gl_FragColor = vec4(
        abs(sin(u_time)),
        st.y,
        m.x,
        abs(sin(gl_FragCoord.x*0.02+gl_FragCoord.y*0.04)));
}
