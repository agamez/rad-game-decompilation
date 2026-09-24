# Software Preservation Porting Task

**Assume this is a software preservation project, not a game reimplementation project.**

Your objective is to preserve the original software as faithfully as possible.

**Prefer literal recovery over understanding.**

Every newly written gameplay algorithm should be treated as a failure unless it replaces functionality that genuinely cannot be recovered from the original executable.

The executable is the source of truth.

Your task is to recover and preserve as much of the original implementation as possible.

---

# Objective

Produce a **source-level Linux port** of an old MS-DOS game.

The game archive is available here:

https://ibeerc.gmr.ssr.upm.es/nextcloud/index.php/s/jiyEaBJJbKXjbgq

The final result should compile and run natively on modern Linux.

The objective is **not** to recreate the game based on observed behavior.

The objective is to recover the original implementation and make it portable with the smallest possible set of platform-specific changes.

---

# Primary Rule

**Treat the original executable as the authoritative source.**

Whenever possible:

* Recover the original C code by decompilation.
* Preserve original functions.
* Preserve original control flow.
* Preserve original algorithms.
* Preserve original data structures.
* Preserve original lookup tables.
* Preserve original state machines.
* Preserve original arithmetic.
* Preserve original memory layout where practical.
* Preserve original bugs unless they prevent execution.

Do not redesign existing code.

Do not replace algorithms with cleaner implementations.

Do not "improve" the code.

If the recovered code looks ugly, inefficient or redundant, keep it exactly that way.

Behavioral fidelity is far more important than readability.

---

# Decompilation Strategy

Recover the implementation mechanically whenever possible.

The executable already contains the correct implementation.

Do not reinterpret it.

Do not reverse engineer the game mechanics in order to write new code.

Recover the code instead.

Never attempt to deduce:

* sprite generation
* rendering algorithms
* collision algorithms
* animation systems
* AI
* movement logic
* timing logic
* resource loading
* level logic
* object behavior
* physics

If these exist inside the executable, recover them literally.

Whenever there is a choice between:

* understanding an algorithm and rewriting it

or

* preserving the recovered implementation

always choose the recovered implementation.

---

# Code Fidelity

The finished project should contain the highest possible percentage of code that originates from the decompiled executable.

Treat the project as a **ported decompilation**, not a remake.

Avoid refactoring.

Avoid simplifying expressions.

Avoid rewriting goto-heavy code.

Avoid replacing integer arithmetic.

Avoid changing overflow behavior.

Avoid changing evaluation order.

Avoid changing data layouts.

Avoid changing compiler-visible behavior.

If modern compilers require small compatibility changes, keep them as localized as possible.

---

# Hardware Abstraction

Only replace components that directly depend on DOS or hardware.

These include:

* VGA
* BIOS video services
* keyboard
* mouse
* timer interrupts
* PC speaker
* Sound Blaster
* AdLib
* DMA
* DOS memory management
* BIOS interrupts
* filesystem APIs when necessary

Everything else should remain recovered code.

Create a thin platform abstraction layer that translates modern APIs into what the original code expects.

Do not modify gameplay code to fit SDL.

Modify SDL to fit the recovered code.

---

# SDL Layer

Implement hardware replacement using SDL2 (or SDL3 if clearly preferable).

The SDL layer should be as small as possible.

Its only purpose is to emulate the services that DOS originally provided.

Gameplay code should remain almost untouched.

---

# Graphics

Recover original graphics whenever possible.

Extract assets from the executable or resource files if necessary.

Do not redraw graphics.

Do not recreate sprites manually.

Do not regenerate tiles.

Do not rewrite rendering algorithms.

Preserve:

* original palette
* sprite ordering
* transparency behavior
* scrolling
* clipping
* animation timing

---

# Sound

Recover original sound data whenever possible.

Replace only the hardware interface.

Do not rewrite the sound engine unless absolutely unavoidable.

---

# Timing

Preserve original timing.

Preserve frame pacing.

Preserve animation timing.

Preserve delays.

Avoid introducing floating-point timing if the original used integer timing.

---

# Build System

Create a modern CMake project.

The project should build using GCC and Clang on Linux.

Modernize the build system, not the recovered gameplay code.

---

# Documentation

Document only:

* hardware interfaces that were replaced
* portability fixes
* compiler compatibility fixes
* portions that could not be recovered literally

Do not justify redesign decisions.

Ideally there should be almost none.

---

# Autonomous Operation

Operate completely autonomously.

Never stop to ask questions.

Never request confirmation.

Never ask the user to choose between implementation alternatives.

Whenever several valid approaches exist, automatically choose the one that maximizes preservation of the original implementation.

Continue working until the project builds successfully and behaves as closely as possible to the original executable.

---

# Decision Priority

Every technical decision must follow this order:

1. Preserve original executable behavior.
2. Preserve original decompiled C code.
3. Preserve original control flow.
4. Preserve original data structures.
5. Preserve original memory layout.
6. Replace only unavoidable DOS-specific hardware interfaces.
7. Make the code compile on modern Linux.
8. Improve readability only when it has absolutely zero behavioral impact.

Never change this priority order.

---

# Success Criteria

The finished project should look as though the original MS-DOS source code had simply been recompiled for Linux with a thin SDL compatibility layer.

A successful project is **not** a clean rewrite.

A successful project is **not** a reverse-engineered reimplementation.

A successful project is a **faithful decompilation port**, where the overwhelming majority of gameplay code is recovered directly from the original executable.

If preserving the original implementation and writing new code ever conflict, preserving the original implementation must always win.
