# Worklog 013

- Kept the sealed 012 checkpoint as a recovery point and continued static original-code integration.
- Imported `sub_82097720` unchanged and proved its existing-key ordered-map path without invoking unsupported insertion/allocation helpers.
- Imported the 20,449-byte `sub_820915F0` generated body unchanged.
- Added explicit non-success boundaries for unported direct dependencies. Unknown virtual calls continue to fail through the normal dispatch error path.
- Built an end-to-end synthetic chain through `8209DE50 -> 82097720 -> 820915F0`; original timeline state advances from 2.0f to 2.0f + 1/60 before the first unknown movie virtual.
- Added shared `runtime013::synthetic_chain_test()` so the same 7/7 contract can run on the eventual native Xbox build without using synthetic state as a substitute for real captured state.
- Prepared `nxdk-update013` to run the new synthetic self-test and captured-startup boundary test ahead of the retained 011 render acceptance.
- Re-ran Release and ASan/UBSan acceptance. All five CTest targets pass in both configurations; retained widget, visibility and fixture suites also pass.
- Stopped static expansion at the movie-object virtual boundary because the old render capture does not contain `owner+0` or its vtable. The prepared live PC update tracer is the evidence-preserving next step.
