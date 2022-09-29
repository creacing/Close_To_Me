<template>
  <div class="pace pace-inactive pace-inactive">
    <div
      class="pace-progress"
      data-progress-text="100%"
      data-progress="99"
      style="transform: translate3d(100%, 0px, 0px)"
    >
      <div class="pace-progress-inner"></div>
    </div>
    <div class="pace-activity"></div>
  </div>
  <!-- <Loading :showLoading="showLoading" /> -->
  <div id="container">
    <!-- 头部 -->
    <header id="header" itemscope itemtype="http://schema.org/WPHeader">
      <Nav />
    </header>
    <!-- 波浪 -->
    <wave />
    <!-- 主体 -->
    <main>
      <!-- 主体内容 -->
      <LayOut>
        <template v-slot:content>
          <RouterView />
        </template>
      </LayOut>
    </main>
    <!-- 页脚 -->
    <footer id="footer">
      <Footer />
    </footer>
  </div>
</template>  
<script setup>
import { RouterView } from "vue-router";
import Nav from "@/components/Nav.vue";
import Loading from "@/components/Loading.vue";
import Footer from "@/components/Footer.vue";
import Wave from "@/components/Wave.vue";
import LayOut from "@/views/LayOut.vue";
import { onMounted, ref } from "vue";

import initAnime from "@/utils/clickAnime.js";
const showLoading = ref(false)

onMounted(() => {
  document.addEventListener(
    "click",
    function (e) {
      initAnime(e);
    },
    false
  );

  // document.addEventListener('visibilitychange', () => {
  //   switch (document.visibilityState) {
  //     case 'hidden':
  //       showLoading.value = true
  //       break;
  //     case 'visible':
  //       setTimeout(function () {
  //         showLoading.value = false
  //       }, 2000);
  //       break;
  //   }
  // });

});


</script>
<style lang="scss" scoped>
</style>
