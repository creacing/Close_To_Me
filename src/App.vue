<template>
  <div id="container">
    <header id="header">
      <Nav />
    </header>
    <Wave />
    <main>
      <LayOut>
        <template v-slot:content>
          <RouterView />
        </template>
      </LayOut>
    </main>
    <footer id="footer">
      <Footer />
    </footer>
  </div>
</template>  
<script setup>
import { RouterView } from "vue-router";
import Nav from "@/components/Nav.vue";
import Footer from "@/components/Footer.vue";
import Wave from "@/components/Wave.vue";
import LayOut from "@/views/LayOut.vue";
import { onMounted, ref } from "vue";

import initAnime from "@/utils/clickAnime.js";
const showLoading = ref(false)
// register global animation
onMounted(() => {
  document.addEventListener(
    "click",
    function (e) {
      initAnime(e);
    },
    false
  );
});
</script>
<style lang="scss" scoped>
#footer {
  color: var(--grey-5);
  font-size: 0.875em;
  background: var(--body-bg-shadow);
}
</style>
