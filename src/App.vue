<template>
  <div id="blog" class="flex-col pos-rel">
    <header id="header" class="pos-rel">
      <Nav />
    </header>
    <Wave id="waves" />
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
const showLoading = ref(false);

// register global animation
const init = () => {
  document.addEventListener("click", function (e) { initAnime(e); }, false);
}

onMounted(() => {
  init()
});


</script>
<style lang="scss" scoped>
#blog {
  min-height: 100%;
  min-width: 100%;
  #header {
    margin: 0 auto;
    width: 100%;
    height: 50vh;
    text-shadow: 0 0.2rem 0.3rem rgba(0, 0, 0, 0.5);
    color: var(--header-text-color);
  }

  main {
    background: linear-gradient(
        to top,
        var(--body-bg-shadow) 0,
        var(--grey-1) 20%
      )
      no-repeat bottom;
    z-index: 999;
  }

  #footer {
    color: var(--grey-5);
    font-size: 0.875em;
    background: var(--body-bg-shadow);
  }
}
</style>
